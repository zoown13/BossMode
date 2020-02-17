// Fill out your copyright notice in the Description page of Project Settings.

#include "BMAIController.h"
#include "BMBossCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BMCharacter.h"
#include "BMProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


ABMAIController::ABMAIController() {

	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	check(BlackboardComp);
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	check(BehaviorTreeComp);

}

void ABMAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	ControlledChar = Cast<ABMBossCharacter>(InPawn);
	if (InPawn != nullptr) {

		BlackboardComp->InitializeBlackboard(*(ControlledChar->BehaviorTree->BlackboardAsset));
		BehaviorTreeComp->StartTree(*(ControlledChar->BehaviorTree));
		BossStateBlackboardKey = BlackboardComp->GetKeyID("BossState");
		TargetBlackboardKey = BlackboardComp->GetKeyID("TargetToFollow");
	}
}

UBlackboardComponent * ABMAIController::GetBlackboard()
{
	return BlackboardComp;
}

void ABMAIController::Tick(float Deltaseconds) {
	EBossState bossState;
	if (ControlledChar->GetHealth() > 66.0f) {
		bossState = EBossState::BS_FOLLOW;
	}
	else if (ControlledChar->GetHealth() > 33.0f) {
		bossState = EBossState::BS_TURRET;
	}
	else {
		bossState = EBossState::BS_FINAL;
	}

	BlackboardComp->SetValue<UBlackboardKeyType_Enum>(BossStateBlackboardKey, (uint8)bossState);

	if (bIstracking && Target != nullptr) {
		FVector CharLoc = ControlledChar->GetActorLocation();
		FVector dirToTarget = Target->GetActorLocation()-CharLoc;
		FRotator rotToTarget = dirToTarget.Rotation();
		ControlledChar->SetActorRotation(FMath::Lerp(ControlledChar->GetActorRotation(), rotToTarget, Deltaseconds * 5));
	}
}

void ABMAIController::TrackToTarget()
{
	Target = Cast<ABMCharacter>(BlackboardComp->GetValue<UBlackboardKeyType_Object>(TargetBlackboardKey));
	if (Target != nullptr) {
		bIstracking = true;
	}
}

void ABMAIController::StopTrack()
{
	bIstracking = false;
	Target = nullptr;
}

void ABMAIController::FireMissiles()
{
	if (Target) {
		//�߻� ���� ã��(5)
		for (int i = 1; i <= 5; ++i) {
			float fAngle = 16 + i * 26;
			FVector circlePoint;
			circlePoint.X = (FMath::Cos((fAngle*PI / 180.0f)));
			circlePoint.Y = (FMath::Cos(PI / 2)*FMath::Sin((fAngle*PI / 180.0f)));
			circlePoint.Z = (FMath::Sin(PI / 2)*FMath::Sin((fAngle*PI / 180.0f)));

			FRotator charRot = ControlledChar->GetActorRotation();

			charRot.Yaw = charRot.Yaw + 90.0f;
			circlePoint = charRot.RotateVector(circlePoint);

			FVector SpawnLoc = ControlledChar->GetActorLocation() + circlePoint * 180.0f;
			ABMProjectile* pThisProj = GetWorld()->SpawnActor<ABMProjectile>(Target->ProjectileClass, SpawnLoc, ControlledChar->GetActorRotation());
			pThisProj->GetProjectileMovement()->HomingTargetComponent = Cast<USceneComponent>(Target->GetComponentByClass(USceneComponent::StaticClass()));
		}//for�� �ݱ�
	}//if�� �ݱ�
}//�Լ� �ݱ�

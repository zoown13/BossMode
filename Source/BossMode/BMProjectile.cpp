// Fill out your copyright notice in the Description page of Project Settings.

#include "BMProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABMProjectile::ABMProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

 	//��ü�� ������ �浹 ǥ������ ����Ѵ�
	ProjCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));

	ProjCollision->InitSphereRadius(10.0f);
	ProjCollision->BodyInstance.SetCollisionProfileName("BlockAll");
	ProjCollision->OnComponentHit.AddDynamic(this, &ABMProjectile::OnHit);

	OnDestroyed.AddDynamic(this, &ABMProjectile::OnDestroyedProjectile);

	ProjCollision->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));

	ProjCollision->CanCharacterStepUpOn = ECB_No;

	RootComponent = ProjCollision;

	//����ƽ�޽� ������Ʈ ����
	ProjMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ProjMesh->SetupAttachment(ProjCollision);
	ProjMesh->SetCollisionProfileName(TEXT("NoCollision"));

	//��ƼŬ������Ʈ ����
	ProjParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	ProjParticle->bAutoActivate = false;
	ProjParticle->SetupAttachment(ProjCollision);

	//�߻�ü�� �̵��� �����ϱ� ���� ProjectileMovementComponent���
	ProjMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));

	ProjMovement->UpdatedComponent = ProjCollision;
	ProjMovement->InitialSpeed = 3000.f;
	ProjMovement->MaxSpeed = 3000.f;
	ProjMovement->bRotationFollowsVelocity = true;

	//�⺻������ 3�� �� ����
	InitialLifeSpan = 3.0f;
}

void ABMProjectile::OnHit(class UPrimitiveComponent* HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if (!OtherActor->GetClass()->IsChildOf(this->StaticClass())) {

		ProjCollision->SetCollisionProfileName(TEXT("NoCollision"));
		ProjCollision->bGenerateOverlapEvents = false;
		ProjMesh->SetVisibility(false);

		ProjParticle->Activate();
		ProjParticle->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	}
}

void ABMProjectile::OnDestroyedProjectile(AActor * DestroyinActor)
{
}

// Called when the game starts or when spawned
void ABMProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABMProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


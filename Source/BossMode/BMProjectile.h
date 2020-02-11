// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BMProjectile.generated.h"


UCLASS()
class BOSSMODE_API ABMProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABMProjectile();

	/** �߻�ü�� ���𰡿� �ε����� �� ȣ���� */
	UFUNCTION()
		void OnHit(class UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnDestroyedProjectile(AActor* DestroyinActor);//�߻�ü�� ����� �� ȣ��

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	/** ��ü �ݸ��� ������Ʈ */

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* ProjCollision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		class UParticleSystemComponent* ProjParticle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ProjMesh;

	/** �߻�ü ������ ������Ʈ */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjMovement;
	 
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BMProjectile.h"
#include "BMCharacter.generated.h"

UCLASS()
class BOSSMODE_API ABMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABMCharacter();

	//기본 회전 속도(deg/sec)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	//기본 위/아래 보기 속도(deg/sec)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	//사용할 발사체 클래스
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<ABMProjectile> ProjectileClass;

	//발사체 생성
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile)
		class USceneComponent* ProjSpawn;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//전방 및 후방 이동 처리(음수 값이 입력되면 뒤로이동한다)
	void MoveForward(float Val);

	//좌우 스트레이핑 이동 처리(음수 값이 입력되면 왼쪽으로이동한다)
	void MoveRight(float Val);

	/**
	* input axis 매핑을 통해 호출
	* @param Rate 정규화된 속도이며 1.0이 최대 회전 속도이다.
	*/
	void TurnAtRate(float Rate);

	/**
	* 위 아래를 주어진 속도로 보기 위해 입력에서 호출한다.
	* @param Rate 정규화된 속도이며 1.0이 최대 회전 속도이다.
	*/
	void LookUpRate(float Rate);

	/** 발사체 발사하기*/
	void OnFire();

	//발사체 추적대상
	USceneComponent* TrackingSceneComponent;

	//추적함수
	void OnTrack();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//APawn 인터페이스
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//APawn 인터페이스 종료

private:

	//폰 메시, 자신만 볼 수 있음
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FPMesh;

	//건 메시, 자신만 볼 수 있음
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FPGunMesh;
	
	//1인칭 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FPCameraComponent;


};

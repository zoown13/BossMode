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

	//�⺻ ȸ�� �ӵ�(deg/sec)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	//�⺻ ��/�Ʒ� ���� �ӵ�(deg/sec)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	//����� �߻�ü Ŭ����
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<ABMProjectile> ProjectileClass;

	//�߻�ü ����
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile)
		class USceneComponent* ProjSpawn;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//���� �� �Ĺ� �̵� ó��(���� ���� �ԷµǸ� �ڷ��̵��Ѵ�)
	void MoveForward(float Val);

	//�¿� ��Ʈ������ �̵� ó��(���� ���� �ԷµǸ� ���������̵��Ѵ�)
	void MoveRight(float Val);

	/**
	* input axis ������ ���� ȣ��
	* @param Rate ����ȭ�� �ӵ��̸� 1.0�� �ִ� ȸ�� �ӵ��̴�.
	*/
	void TurnAtRate(float Rate);

	/**
	* �� �Ʒ��� �־��� �ӵ��� ���� ���� �Է¿��� ȣ���Ѵ�.
	* @param Rate ����ȭ�� �ӵ��̸� 1.0�� �ִ� ȸ�� �ӵ��̴�.
	*/
	void LookUpRate(float Rate);

	/** �߻�ü �߻��ϱ�*/
	void OnFire();

	//�߻�ü �������
	USceneComponent* TrackingSceneComponent;

	//�����Լ�
	void OnTrack();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//APawn �������̽�
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//APawn �������̽� ����

private:

	//�� �޽�, �ڽŸ� �� �� ����
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FPMesh;

	//�� �޽�, �ڽŸ� �� �� ����
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FPGunMesh;
	
	//1��Ī ī�޶�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FPCameraComponent;


};

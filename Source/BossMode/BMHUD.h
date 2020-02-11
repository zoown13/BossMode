// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BMHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSSMODE_API ABMHUD : public AHUD
{
	GENERATED_BODY()
	
	
public:

	ABMHUD();

	/** HUD�� �⺻ ��ο� �� */
	virtual void DrawHUD() override;

private:
	/** ũ�ν���� ���� ������ */
	class UTexture2D* CrosshairTex;
	
};

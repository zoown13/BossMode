// Fill out your copyright notice in the Description page of Project Settings.

#include "BossModeGameMode.h"
#include "UObject/ConstructorHelpers.h"

ABossModeGameMode::ABossModeGameMode() :Super() {

	//�������Ʈ ĳ���͸� �⺻ �� Ŭ������ �����ϱ�
	static ConstructorHelpers::FClassFinder<APawn>PlayerPawnClassFinder(TEXT("/Game/Blueprint/FPCharacter"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;


}



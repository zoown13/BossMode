// Fill out your copyright notice in the Description page of Project Settings.

#include "BossModeGameMode.h"
#include "UObject/ConstructorHelpers.h"

ABossModeGameMode::ABossModeGameMode() :Super() {

	//블루프린트 캐릭터를 기본 폰 클래스로 설정하기
	static ConstructorHelpers::FClassFinder<APawn>PlayerPawnClassFinder(TEXT("/Game/Blueprint/FPCharacter"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;


}



// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BMArgoCheck.generated.h"

/**
 * 
 */
UCLASS()
class BOSSMODE_API UBMArgoCheck : public UBTService
{
	GENERATED_BODY()
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	UBehaviorTree* ThisTree;
	class ABMAIController* ThisController;
	class ABMBossCharacter* ThisAICharacter;
	
	
};

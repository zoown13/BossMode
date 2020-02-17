// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BMRandomMoveTo.generated.h"

/**
 * 
 */
UCLASS()
class BOSSMODE_API UBMRandomMoveTo : public UBTTaskNode
{
	GENERATED_BODY()
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
private:
	UBehaviorTree* ThisTree;
	class ABMAIController* ThisController;
	
	
	
};

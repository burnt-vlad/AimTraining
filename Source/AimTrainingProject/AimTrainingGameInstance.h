// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AimTrainingGameInstance.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChanged, EMatchState);

UENUM(BlueprintType)
enum class EMatchState :uint8
{
	WaitingForTheStart,
	InProgress,
	Pause,
	GameOver
};

UCLASS()
class AIMTRAININGPROJECT_API UAimTrainingGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

};

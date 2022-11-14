// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AimTrainingProject/AimTrainingGameInstance.h"
#include "BasePlayerController.generated.h"

UCLASS()
class AIMTRAININGPROJECT_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
	void OnPausePressed();
	void OnMatchStateChanged(EMatchState State);
};

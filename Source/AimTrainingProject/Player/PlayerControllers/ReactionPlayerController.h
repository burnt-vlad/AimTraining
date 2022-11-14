// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "AimTrainingProject/Player/PlayerControllers/BasePlayerController.h"
#include "ReactionPlayerController.generated.h"

UCLASS()
class AIMTRAININGPROJECT_API AReactionPlayerController : public ABasePlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};

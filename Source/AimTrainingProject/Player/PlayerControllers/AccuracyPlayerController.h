// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerController.h"
#include "AccuracyPlayerController.generated.h"


UCLASS()
class AIMTRAININGPROJECT_API AAccuracyPlayerController : public ABasePlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};

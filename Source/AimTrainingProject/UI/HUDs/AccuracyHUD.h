// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "BaseHUD.h"
#include "AccuracyHUD.generated.h"

UCLASS()
class AIMTRAININGPROJECT_API AAccuracyHUD : public ABaseHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
};

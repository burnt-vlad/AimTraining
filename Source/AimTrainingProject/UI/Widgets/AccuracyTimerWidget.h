// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AccuracyTimerWidget.generated.h"

class AAccuracyGameMode;

UCLASS()
class AIMTRAININGPROJECT_API UAccuracyTimerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		int32 GetTimeRemaining() const;

private:
	AAccuracyGameMode* GetAccuracyGameMode() const;
};

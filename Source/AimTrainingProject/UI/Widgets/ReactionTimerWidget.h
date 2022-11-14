// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ReactionTimerWidget.generated.h"

class AReactionGameMode;

UCLASS()
class AIMTRAININGPROJECT_API UReactionTimerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
		int32 GetTimeRemaining() const;

private:
	AReactionGameMode* GetReactionGameMode() const;
};

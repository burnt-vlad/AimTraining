// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "AimTrainingProject/UI/Widgets/BaseGameOverWidget.h"
#include "AccuracyGameOverWidget.generated.h"

class UButton;

UCLASS()
class AIMTRAININGPROJECT_API UAccuracyGameOverWidget : public UBaseGameOverWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		UButton* GoToReactionGameModeButton;
private:
	UFUNCTION()
		void OnGoToReactionGameMode();
};

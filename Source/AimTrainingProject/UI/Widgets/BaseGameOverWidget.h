// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AimTrainingProject/AimTrainingGameInstance.h"
#include "BaseGameOverWidget.generated.h"

class UButton;

UCLASS()
class AIMTRAININGPROJECT_API UBaseGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;
	UPROPERTY(meta = (BindWidget))
		UButton* RestartButton;
	UFUNCTION()
		void OnResetLevel();
};

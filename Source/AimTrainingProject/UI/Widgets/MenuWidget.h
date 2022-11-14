// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

class UButton;
class UAimTrainingGameInstance;

UCLASS()
class AIMTRAININGPROJECT_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* StartTrainingButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnStartGame();

	UAimTrainingGameInstance* GetAimTrainingGameInstance() const;
};

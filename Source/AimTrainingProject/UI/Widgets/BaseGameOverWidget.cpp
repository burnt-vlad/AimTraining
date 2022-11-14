// Aim Training Game. Fedosov Vladislav


#include "BaseGameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UBaseGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (RestartButton)
	{
		RestartButton->OnClicked.AddDynamic(this, &UBaseGameOverWidget::OnResetLevel);
	}
}

void UBaseGameOverWidget::OnResetLevel()
{
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}

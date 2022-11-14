// Aim Training Game. Fedosov Vladislav


#include "BasePauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"

void UBasePauseWidget::NativeOnInitialized()
{
	const auto InitStatus = Super::Initialize();
	if (ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UBasePauseWidget::OnResume);
	}
	if (RestartButton)
	{
		RestartButton->OnClicked.AddDynamic(this, &UBasePauseWidget::OnResetLevel);
	}
}

void UBasePauseWidget::OnResume()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	GetWorld()->GetAuthGameMode()->ClearPause();
}

void UBasePauseWidget::OnResetLevel()
{
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}
#include "PersonalMoneyTracker.h"

void PersonalMoneyTracker::registration()
{
    userManager.registration();
}

void PersonalMoneyTracker::loggingIn()
{
    userManager.loggingIn();
}

void PersonalMoneyTracker::changePassword()
{
    userManager.changePassword();
}

void PersonalMoneyTracker::logout()
{
    userManager.logout();
}

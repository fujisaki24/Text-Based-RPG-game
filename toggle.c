#include "object.h"

static void swapLocations(OBJECT *obj1, OBJECT *obj2)
{
   OBJECT *tmp = obj1->location;
   obj1->location = obj2->location;
   obj2->location = tmp;
}

const char *cannotBeOpened(void)    { return "That cannot be opened.\n";    }
const char *cannotBeClosed(void)    { return "That cannot be closed.\n";    }
const char *cannotBeLocked(void)    { return "That cannot be locked.\n";    }
const char *cannotBeUnlocked(void)  { return "That cannot be unlocked.\n";  }

const char *isAlreadyOpen(void)     { return "That is already open.\n";     }
const char *isAlreadyClosed(void)   { return "That is already closed.\n";   }
const char *isAlreadyLocked(void)   { return "That is already locked.\n";   }
const char *isAlreadyUnlocked(void) { return "That is already unlocked.\n"; }

const char *isStillOpen(void)       { return "That is still open.\n";       }
const char *isStillLocked(void)     { return "That is locked.\n";           }

const char *toggleBackdoor(void)
{
   swapLocations(openDoorToBackroom, closedDoorToBackroom);
   swapLocations(openDoorToLibrary, closedDoorToLibrary);
  swapLocations(openDoorToSherlock, closedDoorToSherlock);
  swapLocations(openDoorToSeclock, closedDoorToSeclock);
   return "OK.\n";
}

const char *toggleBox(void)
{
  swapLocations(openBoxWood, closedBoxWood);
   return "OK.\n";
}

const char* toggleBoxLock(void)
{
    if (libraryKeys->location == player)
    {
        swapLocations(closedDoorToLibrary, lockedDoorToLibrary);
        return "OK.\n";
    }
    
   
    else
    {
        return "You don't have a key.\n";
    }
}

const char* toggleSherLock(void)
{
    if (sherlockKey->location == player)
    {
        swapLocations(closedDoorToSherlock, lockedDoorToSherlock);
        return "OK.\n";
    }

    else
    {
        return "You don't have a key.\n";
    }
}

const char* toggleSecLock(void)
{
    if (secretBook->location == player)
    {
        swapLocations(closedDoorToSeclock, lockedDoorToSeclock);
        return "OK.\n";
    }

    else
    {
        return "You don't have a key.\n";
    }
}

 
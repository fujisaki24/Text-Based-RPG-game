#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "match.h"
#include "noun.h"
#include "reach.h"
static void talk(const char* about, OBJECT* to)
{
    OBJECT* topic = getTopic(about);
    if (topic == NULL)
    {
        printf("I don't understand what you want to talk about.\n");
    }
    else
    {
        if (topic->level == 1) {
            printf("You hear %s say: '%s'\n",
                to->description,
                topic == to ? "I don't want to talk about myself."
                : topic->gossip_1);
        }
        else if (topic->level == 2) {
            printf("You hear %s say: '%s'\n",
                to->description,
                topic == to ? "I don't want to talk about myself."
                : topic->gossip_2);
        }
        

        else
        {
            printf("You hear %s say: '%s'\n",
                to->description,
                topic == to ? "I don't want to talk about myself."
                : topic->gossip_3);
        }

        
    }
}
bool executeTalk(void)
{
    OBJECT* to = actorHere();
    if (to != NULL)
    {
        talk(params[0], to);
    }
    else
    {
        printf("There is nobody here to talk to.\n");
    }
    return true;
}
bool executeTalkTo(void)
{
    OBJECT* to = reachableObject("who to talk to", params[1]);
    if (to != NULL)
    {
        if (to->health > 0)
        {
            talk(params[0], to);
        }
        else
        {
            printf("There is no response from %s.\n", to->description);
        }
    }
    return true;
}
#ifndef _CRAFTING_H_
#define _CRAFTING_H_

#include <string>
#include <vector>
#include <map>
#include "itype.h"
#include "skill.h"
#include "rng.h"

#define MAX_DISPLAYED_RECIPES 18

typedef std::string craft_cat;

struct component
{
 itype_id type;
 int count;
 component() { type = "null"; count = 0; }
 component(itype_id TYPE, int COUNT) : type (TYPE), count (COUNT) {}
};

struct recipe {
  std::string ident;
  int id;
  itype_id result;
  craft_cat cat;
  Skill *sk_primary;
  Skill *sk_secondary;
  int difficulty;
  int time;
  bool reversible; // can the item be disassembled?
  bool autolearn; // do we learn it just by leveling skills?
  int learn_by_disassembly; // what level (if any) do we learn it by disassembly?

  std::vector<std::vector<component> > tools;
  std::vector<std::vector<component> > components;

  recipe() {
    id = 0;
    result = "null";
    sk_primary = NULL;
    sk_secondary = NULL;
    difficulty = 0;
    time = 0;
    reversible = false;
    autolearn = false;
  }

recipe(std::string pident, int pid, itype_id pres, craft_cat pcat, const char *p1,
       const char *p2, int pdiff, int ptime, bool preversible, bool pautolearn,
       int plearn_dis) :
  ident (pident), id (pid), result (pres), cat(pcat), difficulty (pdiff), time (ptime),
  reversible (preversible), autolearn (pautolearn), learn_by_disassembly (plearn_dis)
  {
    sk_primary = p1?Skill::skill(p1):NULL;
    sk_secondary = p2?Skill::skill(p2):NULL;
  }
};


typedef std::vector<recipe*> recipe_list;
typedef std::map<craft_cat, recipe_list> recipe_map;

#endif

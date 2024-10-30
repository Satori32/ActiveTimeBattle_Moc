#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <memory.h>

#include "FixedVector.h"

struct Statas {
	int16_t Str = 0;
	int16_t Dex = 0;
	int16_t Int = 0;
	int16_t Spd = 0;
};

Statas ConstructStatas(int16_t Str, int16_t Dex, int Int, int Spd) {
	Statas S;
	S.Str = Str;
	S.Dex = Dex;
	S.Int = Int;
	S.Spd = Spd;

	return S;
}

bool Free(Statas& In) {
	In.Str = 0;
	In.Dex = 0;
	In.Int = 0;
	In.Spd = 0;

	return true;
}
struct Parsonal {
	char* Name = NULL;
	int16_t Age = 0;
	int16_t Sex = 0;//ê´ï 
	int16_t Exp = 0;
	int16_t Parmittion[128] = { 0, };//can replace vector.
};

struct SkilItem {
	char* Name = NULL;
	int16_t ID = 0;
	int16_t CastTime = 0;
	int16_t Wait = 0;
	int16_t Cost = 0;//maybe mana.
	//type T = NULL;
	typedef int T;
	T Hide;
};
template<class T>
SkilItem ConstructSkilItem<T>(char* Name,int16_t ID, int16_t CastTime, int16_t Wait, int16_t Cost, T& Hide) {
	SkilItem S;

	S.Name = Name;
	S.ID = ID;
	S.CastTime = CastTime;
	S.Wait = Wait;
	S.Cost = Cost;
	S.Hide = Hide;
	//S.T = T;
	return S;
}
bool Free(SkilItem& In) {
	//Free(In.Name);
	Free(In.ID);
	Free(In.CastTime);
	Free(In.Wait);
	Free(In.Cost);
	Free(In.Hide);

	//In.Name = NULL;
	In.ID = 0;
	In.CastTime = 0;
	In.Wait = 0;
	In.Cost = 0;
	
	return true;
}

struct SkillBag {
	FixedVector<SkilItem, 255> Skills;
};
struct ClassInfo {
	char* JobName = NULL;
	int16_t Exp = 0;
	int16_t Parmittion[128] = { 0, };//can swap vector.
	SkillBag Skills;
};

struct Item {
	intmax_t ID = 0;
	intmax_t Count = 0;
	//type T = NULL;
	typedef int T;
	T Hide;
};

template<class T>
Item ConstructItem<T>(intmax_t ID, T& Hide) {
	Item I = { 0, };
	I.ID = ID;
	I.Count = 1;
	I.Hide = Hide;
	//I.T = T;
	return I;
}
bool Free(Item& In) {
	Free(In.ID);
	Free(In.Count);
	Free(In.Hide);

	In.ID = 0;
	In.Count = 0;

	return true;
}

struct ItemBag {
	FixedVector<Item, 255> Items;
};
struct Clock {
	int16_t Base = 0;
	int16_t Long = 0;
};

struct BattleInfo{
	Clock Wait;//call to self time
	Clock CastTime;//cast time
	int16_t Parmittion[128] = { 0, };//can replace vector.
	int16_t BadStattud[128] = { 0, };//Any is better??
};
BattleInfo ConstructBattleInfo(Clock Wait, Clock CastTime) {
	BattleInfo B = { 0, };
	B.Wait~= Wait;
	B.CastTime = CastTime;
	return B;
}
bool Free(BattleInfo& In) {
	BattleInfo B = { 0, };
	In = B;
	memset(B.Parmittion, 0, sizeof(B.Parmittion));
	return true;
}
bool IsLocking(BattleInfo& In, BattleSystem& B) {
	int32_t X = In.CastTime.Base + In.CastTime.Long;
	if (B.Count < X) { return true; }
	int32_t Y = In.Wait.Base + In.Wait.Long;
	if (B.Count < Y) { return true; }
	return false;
}
struct AISystem{
	//type T = NULL;
	typedef int T;
	T AI;
};
template<class T>
AISystem ConstructAISystem<T>(T& AI) {
	AISystem A = { 0, };
	A.AI = AI;
	//A.T = T;

	return A;
}
struct AIInfo {
	AISystem AI;
	int16_t Parmittion[128] = { 0, };//can replace vector.
};
AIInfo ConstructAIInfo(AISystem& AI) {
	AIInfo A = { 0. };
	A.AI = AI;

	return A;
}
bool Free(AIInfo& In) {
	Free(In.AI);
	memset(In.Parmittion, 0, sizeof(In.Parmittion));

	return true;	
}

Command Update(AIInfo& In,BattleSystem& B,int16_t CharNum) {
	Command C = { 0, };
	Command D = { 0, };
	AddCommand(C, CharNum);
	D=In.AI,Update(B);
	fot(size_t i = 0; i < Size(D); i++) {
		Push(C.C, *Index(D.C, i));
	}
	return C;
}

struct Profile {
	Parsonal P = { 0, };
	Statas S = { 0, };
	ClassInfo C = { 0, };
	BattleInfo B = { 0, };
	BattleInfo Use = { 0, };
	AIInfo A = { 0, };
};

struct Clock_t {
	clock_t Base = 0;
	clock_t Long = 0;
};

struct Command {
	FixedVector<int16_t, 32> C;
};
bool AddCommand(Command& In, int16_t C) {
	if (Capacity(In.C) <= Size(In.C)) { return false; }
	Push(In.C, C);
	return true;
}
bool SubCommand(Command& In, int16_t C) {
	if (Capacity(In.C) <= Size(In.C)) { return false; }
	Pop(In.C);
	return true;
}

struct BattleSystem{
	FixedVector<Profile, 16> Ally;
	FixedVector<Profile, 16> Enemy;
	intmax_t Count = 0;
	Clock_t Adder;
	clock_t Wait = 0;
	FixedVector<Profile, 34> Box;
};

BattleSystem ConstructBattleSystem(FixedVector<Profile, 16>& A, FixedVector<Profile, 16>& E,clock_t Wait) {
	BattleSystem B = { 0, };
	B.Ally = A;
	B.Enemy = E;
	B.Count = 0;
	B.Wait = Wait;

	return B;
}
bool Free(BattleSystem& In) {
	Free(In.Ally);
	Free(In.Enemy);
	Free(In.Count);
	Free(In.Adder);
	Free(In.Wait);

	In.Count = 0;
	In.Wait = 0;
	return true;
}
bool StartBattle(BattleSystem& In) {
	In.Adder.Base = clock();
	In.Adder.Long = 12;
	In.Wait = 2;
	In.Count = 0;
	//In.Ally//need loop and item.
	//In.Enemy/need loop and Item.
	for (size_t i = 0; i < Size(In.Ally); i++) {
		Push(In.Box, (*Index(In.Ally)),i);
	}
	for (size_t i = 0; i < Size(In.Ally); i++) {
		Push(In.Box, (*Index(In.Enemy)),i);
	}
	return true;
}
bool EndBattle(BattleSystem& In) {
	return false;
}

bool AddCount(BattleSystem& In) {
	In.Count++;
	return true;
}
template<size_t N>
bool Conflict(BattleSystem& In, FixedVector<Command, N>& B) {

}
bool Update(BattleSystem& In) {
	clock_t Now = clock();
	FixedVector<Command, 64> Cs=ConstructFixedVector<Command,64>();


	if (Now+In.Wait< clock()) {
		AddCount(In);
		if (In.Adder.Base + In.Adder.Long < In.Count) {
			for (size_t i = 0; i < Size(In.Box); i++) {
				if (Index(In.Box, i) == NULL) { continue; }
				if (IsLocking(Index(In.Box, i)->B) == true) { continue; }
				Command C = Update(Index(In.Box, i)->A, In);
				Push(Cs, C);
			}
			return Conflict(In, Cs);
		}
	}

	return false;
}
#pragma once
#include "../../../../java/lang/Object/Object.h"

class Minecraft : Object {
public:
	using Object::Object;
	using Object::operator=;
	using Object::operator==;
	static Minecraft getTheMinecraft();
	static bool init();
private:
	inline static Ripterms::JavaClass MinecraftClass{};
};
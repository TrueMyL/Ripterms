#pragma once
#include <iostream>
#include "../../../Ripterms/Ripterms.h"
#include "../../../Ripterms/Maths/Maths.h"
#include "../../../Ripterms/JavaClass/JavaClass.h"

class Object {
public:
	Object(jobject instance, JNIEnv* env = Ripterms::p_env);
	Object(const Object& other_Object);
	Object();
	~Object();

	Object& operator=(const Object& other_Object);
	Object& operator=(jobject instance);
	operator jobject();

	bool isEqualTo(const Object& other_Object);
	bool isValid();
	void clear(); //delete ref
	jobject getInstance() const;
protected:
	inline static Ripterms::JavaClassV2 ObjectClass{ "java/lang/Object" };
	JNIEnv* env = Ripterms::p_env;
	jobject instance = nullptr;
};
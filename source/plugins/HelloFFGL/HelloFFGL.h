#pragma once

//we need to include this file so we can access the functions that are used to create and run an FFGL plugin
#include "FFGLPluginSDK.h"

//we create a class called FFLPlugin, that inherits from CFreeFramePlugin
//this will let us access the functions that we use to create an FFGL plugin
//get texture and parameter data from Resolume,
//and draw pixels in Resolume's output
class FFGLPlugin : public CFreeFrameGLPlugin
{
public:
	FFGLPlugin();
	~FFGLPlugin();

	//these are all FFGL functions that are used to communicate with Resolume
	//what they do is explained in the cpp file
	FFResult ProcessOpenGL(ProcessOpenGLStruct* pGL) override;
	FFResult SetFloatParameter(unsigned int index, float value) override;
	float GetFloatParameter( unsigned int index ) override;
	

	//this is a float that will be set by Resolume, and we can use it to change stuff in our plugin
	//we're going to link the value of this float to the value of the slider in Resolume
	float aFloat;

	//this is boiler plate code that takes care of all the behind the scenes stuff used in creating a plugin
	//in other words, we don't want to mess with this
	static FFResult __stdcall CreateInstance(CFreeFrameGLPlugin **ppOutInstance)
	{
		*ppOutInstance = new FFGLPlugin();
		if (*ppOutInstance != NULL)
			return FF_SUCCESS;
		return FF_FAIL;
	}
};

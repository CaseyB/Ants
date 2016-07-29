package productions.moo.ants;

import android.app.Application;

public class AntApplication extends Application
{
	static
	{
		System.loadLibrary("native-lib");
	}

	@Override
	public void onCreate ()
	{
		super.onCreate();
	}

	@Override
	public void onTerminate ()
	{
		super.onTerminate();
	}
}

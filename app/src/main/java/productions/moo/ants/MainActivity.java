package productions.moo.ants;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity
{
	private static final String TAG = MainActivity.class.getSimpleName();
	private native String getLuaVersion ();

	private Ant[] _ants = new Ant[15];
	private Thread _antRunner;

	@Override
	protected void onCreate (Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		TextView label = (TextView) findViewById(R.id.label);
		label.setText(getLuaVersion());

		for (int i = 0; i < _ants.length; i++)
		{
			_ants[i] = new Ant();
		}
	}

	@Override
	protected void onResume ()
	{
		super.onResume();

		for (int i = 0; i < 10; i++)
		{
			for (Ant ant : _ants)
			{
				Ant.Action action = ant.takeAction();

				switch (action)
				{
					case MOVE_NORTH:
						Log.d(TAG, "Ant: " + ant.id + " MOVE_NORTH");
						break;
					case MOVE_SOUTH:
						Log.d(TAG, "Ant: " + ant.id + " MOVE_SOUTH");
						break;
					case MOVE_EAST:
						Log.d(TAG, "Ant: " + ant.id + " MOVE_EAST");
						break;
					case MOVE_WEST:
						Log.d(TAG, "Ant: " + ant.id + " MOVE_WEST");
						break;
				}
			}
		}
	}
}

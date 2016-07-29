package productions.moo.ants;

public class Ant
{
	public enum Action
	{
		MOVE_NORTH,
		MOVE_SOUTH,
		MOVE_EAST,
		MOVE_WEST
	}

	public final int id;

	private native int addAnt ();
	private native int takeAction (int antID);

	public Ant()
	{
		id = addAnt();
	}

	public Action takeAction()
	{
		int action = takeAction(id);
		return Action.values()[action];
	}
}

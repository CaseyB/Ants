require "Constants"

local lastCommand = nil
local lookCount = 0
local wasBlocked = false

-- This is the main function called by the game
function performTurn()
	if lookCount >= 5 and wasBlocked then
		-- We're trapped!
		return SUICIDE
	end

	if lastCommand == nil then
		-- First time through so look North
		lookCount = lookCount + 1
		lastCommand = LOOK_NORTH
	elseif wasBlocked or 
		lastCommand == MOVE_NORTH or
		lastCommand == MOVE_SOUTH or
		lastCommand == MOVE_EAST or
		lastCommand == MOVE_WEST then

		lookCount = lookCount + 1

		-- Check a different direction
		if lastCommand == LOOK_NORTH or lastCommand == MOVE_EAST then lastCommand = LOOK_EAST
		elseif lastCommand == LOOK_SOUTH or lastCommand == MOVE_WEST then lastCommand = LOOK_WEST
		elseif lastCommand == LOOK_EAST or lastCommand == MOVE_SOUTH then lastCommand = LOOK_SOUTH
		elseif lastCommand == LOOK_WEST or lastCommand == MOVE_NORTH then lastCommand = LOOK_NORTH end
	else
		-- Move whichever direction we just checked
		lookCount = 0
		if lastCommand == LOOK_NORTH then lastCommand = MOVE_NORTH
		elseif lastCommand == LOOK_SOUTH then lastCommand = MOVE_SOUTH
		elseif lastCommand == LOOK_EAST then lastCommand = MOVE_EAST
		else lastCommand = MOVE_WEST end
	end

	return lastCommand
end

function lookResult(contents)
	if contents == WALL or contents == LIVE_ENEMY then
		wasBlocked = true
		print ("Blocked")
	else
		wasBlocked = false
		print ("Not Blocked")
	end
end
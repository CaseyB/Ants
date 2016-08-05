require "Ant"

local min = 0
local max = 10
local instruction = nil
local position = {x = 5, y = 5}

for i=0,100 do
	instruction = performTurn()

	if instruction == LOOK_NORTH then
		-- Look North
		print("Look North")
		if position.y == min then
			print(" - Wall")
			lookResult(WALL)
		else
			lookResult(EMPTY)
		end
	elseif instruction == LOOK_SOUTH then
		-- Look South
		print("Look South")
		if position.y == max then
			lookResult(WALL)
			print(" - Wall")
		else
			lookResult(EMPTY)
		end
	elseif instruction == LOOK_EAST then
		-- Look East
		print("Look East")
		if position.x == max then
			lookResult(WALL)
			print(" - Wall")
		else
			lookResult(EMPTY)
		end
	elseif instruction == LOOK_WEST then
		-- Look West
		print("Look West")
		if position.x == min then
			lookResult(WALL)
			print(" - Wall")
		else
			lookResult(EMPTY)
		end
	elseif instruction == MOVE_NORTH then
		-- Move North
		print("Move North")
		position.y = position.y - 1
		if position.y < min then
			position.y = min
		end
	elseif instruction == MOVE_SOUTH then
		-- Move South
		print("Move South")
		position.y = position.y + 1
		if position.y > max then
			position.y = max
		end
	elseif instruction == MOVE_EAST then
		-- Move East
		print("Move East")
		position.x = position.x + 1
		if position.x > max then
			position.x = max
		end
	elseif instruction == MOVE_WEST then
		-- Move West
		print("Move West")
		position.x = position.x - 1
		if position.x < min then
			position.x = min
		end
	elseif instruction == SUICIDE then
		-- DIE
		break
	end
end
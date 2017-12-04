hook_print("Hello World")

GameEvents.PlayerDoTurn.Add(
	function(playerId)
		hook_print(("Player Id %d did turn."):format(playerId))
	end
)

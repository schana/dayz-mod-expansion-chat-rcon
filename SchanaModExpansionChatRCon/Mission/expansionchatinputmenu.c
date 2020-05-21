modded class ExpansionChatInputMenu extends UIScriptedMenu {
	override bool OnChange (Widget w, int x, int y, bool finished) {
		// super call manually because inheritance is weird
		if (UIScriptedWindow.GetActiveWindows ()) {
			for (int i = 0; i < UIScriptedWindow.GetActiveWindows ().Count (); i++) {
				if (UIScriptedWindow.GetActiveWindows ().GetElement (i).OnChange (w, x, y, finished)) { }
			}
		}

		if (!finished)
			return false;

		string text = m_edit_box.GetText ();

		if (text != "") {
			MissionGameplay gameplayMission = MissionGameplay.Cast (GetGame ().GetMission ());

			string name;
			GetGame ().GetPlayerName (name);

			if (GetGame ().IsMultiplayer ()) {
				if (gameplayMission.GetChatChannel () == ExpansionChatChannels.CCGlobal) {
					gameplayMission.m_ChatChannelName.SetAlpha (0);
					GetExpansionChatBase ().SendGlobalChat (text);
					GetGame ().ChatPlayer ("ᐅ " + text);
				} else {
					GetGame ().ChatPlayer (text);
				}
			}

			if (!GetGame ().IsMultiplayer ()) {
				ChatMessageEventParams chat_params = new ChatMessageEventParams (gameplayMission.GetChatChannel (), name, text, "");
				gameplayMission.m_Chat.Add (chat_params);
			}
		}

		m_close_timer.Run (0.1, this, "Close");

		GetGame ().GetMission ().HideChat ();

		return true;
	}
}
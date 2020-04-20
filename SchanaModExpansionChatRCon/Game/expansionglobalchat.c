modded class ExpansionGlobalChat
{
	void ExpansionGlobalChat()
	{
		GetRPCManager().AddRPC("SchanaMod", "DirectChat", this, SingeplayerExecutionType.Both);
		GetRPCManager().AddRPC("SchanaMod", "DirectChatServer", this, SingeplayerExecutionType.Both);
	}

	void DirectChatServer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param2<string, string> data;
		if (!ctx.Read(data))
			return;

		if (type == CallType.Client)
		{
			GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(ExpansionChatChannels.CCTransport, data.param1, data.param2, ""));
		}
	}

	void DirectChat(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param2<string, string> data;
		if (!ctx.Read(data))
			return;

		if (type == CallType.Server)
		{
			string name = sender.GetName();
			string steamid = sender.GetPlainId();
			string bisid = sender.GetId();
			string idtable = sender.GetPlayerId().ToString();
			string log_date_time = ExpansionGetDateTime();

			string format = "[" + log_date_time + "] " + "[Chat]" + " " + name + "(steamid=" + steamid + ", bisid=" + bisid + ") " + data.param2;

			GetGame().AdminLog(format);

			GetRPCManager().SendRPC("SchanaMod", "DirectChatServer", new Param2<string, string>(data.param1, data.param2));
		}
	}

	void SendDirectChat(string text)
	{
		string name;
		GetGame().GetPlayerName(name);

		GetRPCManager().SendRPC("SchanaMod", "DirectChat", new Param2<string, string>(name, text));
	}
}

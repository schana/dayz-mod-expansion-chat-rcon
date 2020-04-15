modded class Chat
{
    override void Add(ChatMessageEventParams params)
	{
		int channel = params.param1;
        if(channel == 0 || channel == CCDirect)
        {
            return;
        }

        super.Add(params);
	}
}
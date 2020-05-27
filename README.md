# SchanaModExpansionChatRCon

<https://github.com/schana/dayz-mod-expansion-chat-rcon>

<https://steamcommunity.com/sharedfiles/filedetails/?id=2061823484>

This mod alters the Expansion Chat by sending all chat messages through the native
direct chat call, which internally sends an RCon message. This allows side and direct
chat to be read via RCon. Inside the game, side channel messages are duplicated and sent
with the prefix `ᐅ` to the direct channel, which are filtered out before showing to the player.

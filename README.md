# audioflyer
Surround sound audio mixing controlled by serial commands. Making mixes that fly!

Why? Because this is going to be awesome.

The plan is to use a SparkFun Tsunami Wav Trigger board to play lots of audio files. To start off, I plan to use some tasty guitar riffs and various reverbs/effects. Maybe bass, drums and vocals. We shall see. Then play these tracks through a set of 8 speakers arranged in something similar to 7.1 surround.

For amplification, I am using four SparkFun Audio Amps. They are stereo amps, so this will get me 8 channels.

I hope to start many tracks at the same time, and then control their volume in all 8 tracks with serial commands from a micro controller - probably an arduino. I love the idea of using some code to pull off some smooth motions, spatial movements, rotation of the entire mix around my head, "fly by" guitar solos, and even some volume tricks that may be close to impossible to pull off with manual moving of faders, and a big pain to draw in on automation control tracks. This could mean that I want the snare to spin around my head every time I hit it. It might prove to be annoying, but it might also be totally awesome! What about using the random function in arduino to place where each instrument will live for each mix - it means that every listening experience would be unique - pretty F-in' cool if you ask me.

What got me turned onto this idea was binaural recordings. It's basically a technique that's been around for a long time where you put tiny microphones in your ears (facing outward) or you put them on a dummy head, and then record both mics. When you listen to them back on headphones, you can really hear the position of all the sounds. I guess it has something to do with how our brains calculate time differences and bass roll off difference between each ear. Wild stuff! I bought a pair of these mics from The Sound Professionals for 79 bucks and they sound amazing! I can't wait to track some crazy surround sound mixes and then be able to listen back on headphones anywhere and hear the awesome spatial automation.

This has bound to have been done before... but maybe not? I'm not interested in just rocking 5.1 or 7.1 surround mixes with fancy sound cards and cool plugins. I want to control the entire mix from code on a micro. This will open the door to new sound movement effects that I can't even predict at this time.

All I need is volume control for each track to each output. From reading about the Tsunami, it sounds like this is very possible.

How hard can it be?

package;

import flixel.FlxState;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.math.FlxMath;
import flixel.ui.FlxButton;


class PlayState extends FlxState
{

	var _pixie : FlxSprite;
	var _pixies : Array<FlxSprite> = [];

	override public function create()
	{
		super.create();


		_pixie = new flixel.FlxSprite();
		_pixie.loadGraphic ( "assets/images/pixie.png");

		add(_pixie);

		_pixie.x = 100;
		_pixie.y = 100;

		
		// clone pixies
		for (i in 0...100){
			var pc = _pixie.clone();
			pc.x = i * 10;
			add ( pc );
			_pixies.insert ( i, pc );
		}
	}

	override public function update(elapsed:Float)
	{
		super.update(elapsed);

		// draw pixies
		for ( item in _pixies ){
			item.y +=1;
		}
	}
}
	
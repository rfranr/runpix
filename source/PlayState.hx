package;

import flixel.FlxState;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.math.FlxMath;



class PlayState extends FlxState
{

	var _pixie : FlxSprite;
	var _gameNameText : FlxText;

	var _pixies : Array<FlxSprite> = [];


	override public function create()
	{
		super.create();

		_gameNameText = new FlxText ( 0,0, 0, "Run Pixie", 64);

		_gameNameText.screenCenter();

		add(_gameNameText);

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

		var distance = FlxMath.distanceToMouse(_gameNameText);

		_pixie.x =  distance/10;

		// draw pixies
		for ( item in _pixies ){
			item.y +=1;
		}
	}
}
	
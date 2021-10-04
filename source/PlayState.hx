package;

import flixel.FlxState;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.math.FlxMath;
import flixel.ui.FlxButton;
import flixel.tile.FlxTilemap;



class PlayState extends FlxState
{

	var _pixie : FlxSprite;
	var _pixies : Array<FlxSprite> = [];

	var collisionMap:FlxTilemap;

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

		// tilemap
		collisionMap = new FlxTilemap();

		// Initializes the map using the generated string, the tile images, and the tile size
		collisionMap.loadMapFromCSV ("assets/images/tiles/tiles.csv", "assets/images/tiles/tiles.png", 16, 16, AUTO);
		add(collisionMap);

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
	
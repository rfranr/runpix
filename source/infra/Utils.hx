package infra;

typedef MyDataLayers = {
	var data:Array<Int>;
	var height:Int;
	var id:Int;
	var name:Int;
	var opacity:Int;
	var type:String;
	var visible:Bool;
	var width:Int;
	var x:Int;
	var y:Int;
}

typedef MyData = {
	var compressionlevel:Int;
	var height:Int;
	var infinite:Bool;
  	var layers:Array<MyDataLayers>;
	 var nextlayerid:Int;
	 var nextobjectid:Int;
	 var orientation:String;
	 var renderorder:String;
	 var tiledversion:String;
	 var tileheight:Int;
}


class Util
{
	public static function Hello() {
	    /*var s = '{
	      "name": "Haxe",
	      "tags": ["awesome"]
	    }';*/

		var s:String = sys.io.File.getContent("assets/images/tiles/tiles.json");

    	var o:MyData = haxe.Json.parse(s);
    	
    	trace(o.tiledversion); // Haxe (a string)

    	// awesome (a string in an array)
    	trace(o.layers[0].data);
	}

	public static function Map():Array<Int> {
	    /*var s = '{
	      "name": "Haxe",
	      "tags": ["awesome"]
	    }';*/

		var s:String = sys.io.File.getContent("assets/images/tiles/tiles.json");

    	var o:MyData = haxe.Json.parse(s);

    	var dataMap:Array<Int> = o.layers[0].data;
    	for (index in 0...dataMap.length) {
    		var iTile:Int = dataMap[index];
    		if ( iTile > 0 )
    		{
    			dataMap[index] = iTile - 61;
    		}

 		   trace('$index : ${dataMap[index]}');
		}

    	return dataMap;
	}

}
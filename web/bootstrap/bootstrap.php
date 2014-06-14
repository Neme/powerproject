<?php
require('bootstrap/autoloader.php');

class Bootstrap{
	
	
	function __construct(){
        
        //set paths
        Path::set(__DIR__);
        
        if(isset($_GET['url'])){
            $url = $_GET['url'];
            
            if(empty($url )){
                $url[0] = PAGE_DEFAULT;
            }
            else{
                $url = rtrim($url, '/');
            $url = explode('/',$url);
            }
        }
		

		$filename = Path::get('con') . $url[0] . '.php';
		if(!file_exists($filename)){
            $filename = Path::get('con')  . PAGE_ERROR . '.php';
            $url[0] = PAGE_ERROR;
        }
        
        require($filename);
        $controller = new $url[0];
        

        if(isset($url[1])){
            $params = array_slice($url,1);
            foreach($params as $key => $p){
                if(!method_exists($controller, $p)){
                    $url[1] = 'router';
                }
            }
            
            if(!empty($params)){
                call_user_func_array(array($controller,$url[1]),$params);
            }
        }

	}
	
	
	
}

?>
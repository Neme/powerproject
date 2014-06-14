<?php

class Path{
    

    private static $path = array(
        'app' => 'application/',
        
        'con' => 'application/controller/',
        'view' => 'application/view/',
        'mod' => 'application/model/',
        
        'dash' => 'application/controller/dashboard/',
        
        'pub' => 'public/',
        'assets' => 'public/assets/',
        
    );
    
    private static $root = '';
    
    public static function set($root){
        self::$root = dirname($root) . '/';
    }
    
    public static function get($name){
        return self::$root.self::$path[$name];
    }

}
    
?>
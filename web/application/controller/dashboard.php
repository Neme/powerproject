<?php


class Dashboard extends Controller{
    
    private $content = null;
    
    
    
    function __construct(){
        parent::__construct();
        
    }
    
    
    public function router($name){
        
        //ToDo array from db || json file
        $a = array(
            'home', 'ticket'
        );
        
        if(in_array(strtolower($name),$a)){
            $this->loadContent($name);
        }
        else{
             $this->loadContent('home');
        }
        
           
    }
    
    public function loadContent($classname){
        require(Path::get('dash')  . strtolower($classname) . '.php');
        $this->content = new $classname;
        $this->view->content = $this->content;
        $this->view->render('dashboard/dashboard');
    
    }
}

?>
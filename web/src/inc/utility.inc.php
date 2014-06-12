<?php
function loadErrorPage(){
    $errorPath = PAGE_PATH . "/" . ERROR_PAGE;
    if(file_exists( $errorPath )){
        include($errorPath);
    } else {echo "Can't find $errorPath!";}
}

function loadPageFile($filename){
    $file =  PAGE_PATH . "/" . $filename . ".php";
    if(file_exists($file)){
        include($file);
    } else {loadErrorPage();}
}
?>
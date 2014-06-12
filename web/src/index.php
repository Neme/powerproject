<?php
	require("inc/config.inc.php");
	require("inc/utility.inc.php");
	require("inc/database.inc.php");

?>

<!DOCTYPE  html>
<html>
    <head>
    	<title>PowerProject </title>
        <meta charset="utf-8" >
        <meta http-equiv="X-UA-Compatible" content="IE=edge" >
    	<meta name="viewport" content="width=device-width, initial-scale=1" >
        
        <meta name="keywords" content="online project management tool" >
        <meta name="description" content="" >
		<meta name="author" content="Daniel" >
        
        <!-- Bootstrap -->
        <link rel="stylesheet" href="css/bootstrap.min.css">
        <!-- Style -->
		<link rel="stylesheet" href="css/style.css">
        
        
        
        <!-- Javascript -->
        <script src='js/jquery.js'></script>
        <script src='js/holder.js'></script> 
        <script src='js/bootstrap.min.js'></script>
        
        
    </head>
    <body>
    	<header>
            <div class="navbar navbar-default navbar-static-top">
            <div class="row">
            	<div class="col-md-2">
                	<img class="navbar-brand" src="img/logo.png" id="navbar-logo">
                </div>
           		<div class="col-md-8"> </div>
                <div class="col-md-2" >
					<?php loadPageFile("userquick"); ?>
                </div>
            </div>
               
                
            </div>
        </header>
        
        <div class="container-fluid">
			<div class="row">
				<div class="col-md-12">
                    <ol class="breadcrumb">
                        <li><a href="#">Projects</a></li>
                        <li><a href="#">PowerRanger</a></li>
                        <li class="active">Home</li>
                    </ol>
                </div>
            </div>
            <div class="row">
				<div class="col-md-2">

                    <div class="panel panel-default" id="rightNavBar">
                        <div class="panel-body">
                            <ul class="nav nav-pills nav-stacked">
                                <?php
                                	$navItems = array(
                                    	"home" => "Home", 
                                        "ticket" => "Tickets",
                                        "activity" => "Activity",
                                        "doku" => "Documentation",
                                        "calendar" => "Calendar",
										"members" => "Members"
                                    );
                                    
                                    foreach($navItems as $key => $value){
										if(isset($_GET['p']) && !empty($_GET['p'])){
											if($_GET['p'] == $key){
												echo "<li class='active'><a href='?p=$key'>$value</a></li>";
												continue;
											} 
										}
                                    	echo "<li><a href='?p=$key'>$value</a></li>";
                                    }
                                ?>
                            </ul>
                        </div>
        
                    </div>
        		</div>
                <div class="col-md-10" >
                        <div class="panel panel-default" id="rightNavBar">
                        <div class="panel-body">
                               
                            <?php	
								if(isset($_GET['p']) && !empty($_GET['p'])){
									loadPageFile($_GET['p']);
								} else {loadErrorPage();}
							?>
                        </div>
        
                    </div>
                    
                </div>
            </div>
       </div>
    </body>
</html>

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
                                'home'      => 'Home', 
                                'ticket'    => 'Tickets',
                                'activity'  => 'Activity',
                                'doku'      => 'Documentation',
                                'calendar'  => 'Calendar',
                                'members'   => 'Members'
                            );
                           // echo "<li class='active'><a href='?p=$key'>$value</a></li>";

                            foreach($navItems as $dir => $name){
                                echo '<li><a href="'.URL.'dashboard/'.$dir.'">'.$name.'</a></li>';
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
                        if(isset($this->content))
                            $this->content->view->render('dashboard/' . strtolower( get_class($this->content) ),true);
                    ?>
                   
                </div>

            </div>

        </div>
    </div>
</div>
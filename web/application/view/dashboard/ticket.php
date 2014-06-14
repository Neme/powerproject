<script src="<?php echo URL.'public/assets/'; ?>js/ckeditor/ckeditor.js"> </script>
<script type="text/javascript" src="<?php echo URL.'public/assets/'; ?>js/moment.min.js"></script>
<script src="<?php echo URL.'public/assets/'; ?>js/bootstrap-datetimepicker.min.js"></script>
<link rel="stylesheet" href="<?php echo URL.'public/assets/'; ?>css/bootstrap-datetimepicker.min.css">

<script src="<?php echo URL.'public/assets/'; ?>js/bootstrap-slider.js"></script>
<link rel="stylesheet" href="<?php echo URL.'public/assets/'; ?>css/slider.css">

<?php 

function addDatePicker($id){
	echo '
	<div class="form-group">
		<div class="input-group date" id="'.$id.'">
			<input type="text" class="form-control" />
			<span class="input-group-addon"><span class="glyphicon glyphicon-calendar"></span>
			</span>
		</div>
	</div>

	
	<script>
		$(function () {
			$("#'.$id.'").datetimepicker({
				language: "de"
			});
		});
	</script>';
}

function addSlider($id){
	echo '
	<div id="'.$id.'" class="slider slider-horizontal" data-slider-max="100" data-slider-value="0">
	</div>

	
	<script>
		$("#'.$id.'").slider();
	</script>';
}
?>

<!-- new ticket -->

<button class="btn btn-primary" data-toggle="modal" data-target=".bs-example-modal-lg">Ticket erstellen</button>
<br/><br/>
<div class="modal fade bs-example-modal-lg" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">  
        <div class="panel panel-default">
            <div class="panel-heading">Ticket erstellen</div>
            <div class="panel-body">
            	<div class="alert alert-danger" id="ticket-error-box">Fehler: </div>
                <form method="post">
                    <div class="well">
                        <div class="row">
                            <div class="col-md-1"><p>Name</p></div>
                            <div class="col-md-4"><input id="new-ticket-name" class="form-control" type="text"></div>
                            <div class="col-md-1"><p>Zielgruppe</p></div>
                                                
                            <div class="col-md-4">  
                                <div class="input-group">
                                    <div class="input-group-btn">
                                    <button type="button" class="btn btn-default dropdown-toggle" 
                                  	data-toggle="dropdown"> Alle <span class="caret"></span></button>
                                    <ul class="dropdown-menu">
                                        <li><a href="#0" class="new-ticket-group-item-g" >Programmierer</a></li>
                                        <li><a href="#1" class="new-ticket-group-item-g" >Desinger</a></li>
                                        <li><a href="#2" class="new-ticket-group-item-g" >Management</a></li>
                                        <li class="divider"></li>
                                        <li><a href="#0" class="new-ticket-group-item-m">Daniel</a></li>
                                        <li><a href="#1" class="new-ticket-group-item-m">Alex</a></li>
                                        <li><a href="#2" class="new-ticket-group-item-m">Rudi</a></li>
                                        <li><a href="#3" class="new-ticket-group-item-m">Jon</a></li>
                                        <li><a href="#4" class="new-ticket-group-item-m">Ella</a></li>
                                    </ul>
                                    </div>
                                    <input type="text" id="new-ticket-group-text" class="form-control">
                                </div>
                            </div>
                            
                        </div>
                        <br/>
                        <p>Beschreibung</p>
                        <textarea id="descedit" name="editor1"></textarea>
                        <script type="text/javascript">
                            CKEDITOR.replace( "descedit" );
                        </script>
                    </div>
                    <div class="well">
                    
                        <div class="row">
                            <div class="col-md-1"><p>Startzeit</p></div>
                            <div class="col-md-4"><?php addDatePicker("datetimepickerStart"); ?></div>
                        </div>  
                        <div class="row">  
                            <div class="col-md-1"><p>Abgabezeit</p></div>
                            <div class="col-md-4"><?php addDatePicker("datetimepickerEnd"); ?></div>
                        </div>
                        <div class="row">  
                            <div class="col-md-1"><p>Erleding in %</p></div>
                            <div class="col-md-4"><?php addSlider("workDoneProgress"); ?></div>
                            <div class="col-md-1"><p>Aufwand (Studnen)</p></div>
                            <div class="col-md-3"><input  id="new-ticket-group-effort" class="form-control" type="number"></div>
                        </div>
                    </div>
                    <div class="well">
                        <div class="row">
                            <div class="col-md-1"><p>Priorität</p></div>
                            <div class="col-md-3">
                                <div class="btn-group">
                                    <button type="button" id="new-ticket-priority" class="btn btn-default">Niedrig</button>
                                    <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">
                                    <span class="caret"> </span>
                                    </button>
                                    <ul class="dropdown-menu" role="menu">
                                        <li><a href="#0" class="new-ticket-priority-item">Niedrig</a></li>
                                        <li><a href="#1" class="new-ticket-priority-item">Mittel</a></li>
                                        <li><a href="#2" class="new-ticket-priority-item">Hoch</a></li>
                                        <li><a href="#3" class="new-ticket-priority-item">Sehr hoch</a></li>
                                    </ul>
                                </div>
                            </div>
                            <div class="col-md-1"><p>Status</p></div>
                            <div class="col-md-4">
                                <div class="btn-group">
                                    <button type="button" id="new-ticket-status" class="btn btn-default">In Arbeit</button>
                                    <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">
                                    <span class="caret"> </span>
                                    </button>
                                    <ul class="dropdown-menu" role="menu">
                                        <li><a href="#0" class="new-ticket-status-item">1. In Arbeit</a></li>
                                        <li><a href="#1" class="new-ticket-status-item">2. Test notwendig</a></li>
                                        <li><a href="#2" class="new-ticket-status-item">3. Feedback</a></li>
                                        <li><a href="#3" class="new-ticket-status-item">4. Fertig</a></li>
                                        <li class="divider"></li>
                                        <li><a href="#4" class="new-ticket-status-item">Geschlossen</a></li>
                                        <li><a href="#5" class="new-ticket-status-item">Frozen</a></li>
                                    </ul>
                                </div>
                            </div>
                        </div>  
                    </div>
                    <div class="well">
                        <button type="button" class="btn btn-primary" id="ticket-submit">Ticket erstellen</button>
                        <button type="button" class="btn btn-default"  data-dismiss="modal">Schließen</button>
                    </div>
                </form>
        
            </div>
        </div>
    </div>
  </div>
</div>





<!-- ticket list -->


<div class="panel panel-default">
	<div class="panel-heading">Tickets</div>
        <table class="table">
        
        <thead>
            <tr>
                <th>#</th>
                <th>Name</th>
                <th>Priority</th>
                <th>Status</th>
                <th>Users</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>1</td>
                <td>Daniel</td>
                <td>High</td>
                <td>New</td>
                <td>Programmer</td>
            </tr>
        </tbody>
        
        </table>
    <div class="row">
        <div class="col-md-5"></div>
        <div class="col-md-7">
            <ul class="pagination">
                <li><a href="#">&laquo;</a></li>
                <li class="active"><a href="#">1</a></li>
                <li><a href="#">2</a></li>
                <li><a href="#">3</a></li>
                <li><a href="#">4</a></li>
                <li><a href="#">5</a></li>
                <li><a href="#">&raquo;</a></li>
            </ul>
        </div>
	</div>
</div>

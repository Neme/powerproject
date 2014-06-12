<script src='js/ckeditor/ckeditor.js'> </script>
<script type='text/javascript' src='js/moment.min.js'></script>
<script src='js/bootstrap-datetimepicker.min.js'></script>
<link rel='stylesheet' href='css/bootstrap-datetimepicker.min.css'>

<?php 

function addDatePicker($id){
	echo "

	<div class='form-group'>
		<div class='input-group date' id='$id'>
			<input type='text' class='form-control' />
			<span class='input-group-addon'><span class='glyphicon glyphicon-calendar'></span>
			</span>
		</div>
	</div>

	
	<script>
		$(function () {
			$('#$id').datetimepicker({
				language: 'de'
			});
		});
	</script>";
}


?>

<div class='panel panel-default'>
	<div class='panel-heading'>Ticket erstellen</div>
	<div class='panel-body'>
        <form method='post'>
        	<div class='well'>
            	<div class='row'>
                	<div class='col-md-1'><p>Name</p></div>
                    <div class='col-md-4'><input class='form-control' type='text'></div>
                    <div class='col-md-1'><p>Zielgruppe</p></div>
                                    	
                    <div class='col-md-4'>  
                        <div class='input-group'>
                            <div class='input-group-btn'>
                            <button type='button' class='btn btn-default dropdown-toggle' data-toggle='dropdown'>Alle <span class='caret'></span></button>
                            <ul class='dropdown-menu'>
                                <li><a href='#'>Programmierer</a></li>
                                <li><a href='#'>Desinger</a></li>
                                <li><a href='#'>Management</a></li>
                                <li class='divider'></li>
                                <li><a href='#'>Daniel</a></li>
                                <li><a href='#'>Alex</a></li>
                                <li><a href='#'>Rudi</a></li>
                                <li><a href='#'>Jon</a></li>
                                <li><a href='#'>Ella</a></li>
                            </ul>
                            </div>
                            <input type='text' class='form-control'>
                        </div>
                    </div>
                    
                </div>
				<br/>
                <p>Beschreibung</p>
                <textarea id='descedit' name='editor1'></textarea>
                <script type='text/javascript'>
                    CKEDITOR.replace( 'descedit' );
                </script>
            </div>
     		<div class='well'>
            	<div class='row'>
                    <div class='col-md-1'><p>Startzeit</p></div>
                    <div class='col-md-4'><?php addDatePicker('datetimepickerStart'); ?></div>
                </div>  
                <div class='row'>  
                    <div class='col-md-1'><p>Abgabezeit</p></div>
					<div class='col-md-4'><?php addDatePicker('datetimepickerEnd'); ?></div>
                </div>
                <div class='row'>  
                	<div class='col-md-1'><p>Erleding in %</p></div>
                    <div class='col-md-4'><input class='form-control' type='range' min='0' max='100'></div>
                    <div class='col-md-1'><p>Aufwand in Stunden</p></div>
					<div class='col-md-2'><input class='form-control' type='number'></div>
                </div>
            </div>
			<div class='well'>
            	<div class='row'>
                    <div class='col-md-1'><p>Priorität</p></div>
                    <div class='col-md-2'>
                        <div class='btn-group'>
                            <button type='button' class='btn btn-default'>Niedrig</button>
                            <button type='button' class='btn btn-default dropdown-toggle' data-toggle='dropdown'>
                            <span class='caret'> </span>
                            </button>
                            <ul class='dropdown-menu' role='menu'>
                                <li><a href='#'>Niedrig</a></li>
                                <li><a href='#'>Mittel</a></li>
                                <li><a href='#'>Hoch</a></li>
                                <li><a href='#'>Sehr hoch</a></li>
                            </ul>
                        </div>
                    </div>
                    <div class='col-md-1'><p>Status</p></div>
                    <div class='col-md-2'>
                        <div class='btn-group'>
                            <button type='button' class='btn btn-default'>In Arbeit</button>
                            <button type='button' class='btn btn-default dropdown-toggle' data-toggle='dropdown'>
                            <span class='caret'> </span>
                            </button>
                            <ul class='dropdown-menu' role='menu'>
                                <li><a href='#'>1. In Arbeit</a></li>
                                <li><a href='#'>2. Test notwendig</a></li>
                                <li><a href='#'>3. Feedback</a></li>
                                <li><a href='#'>4. Fertig</a></li>
                                <li class='divider'></li>
                                <li><a href='#'>Geschlossen</a></li>
                                <li><a href='#'>Frozen</a></li>
                            </ul>
                        </div>
                    </div>
                </div>  
            </div>
        </form>
        




	</div>
</div>

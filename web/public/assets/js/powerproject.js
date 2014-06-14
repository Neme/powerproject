$( document ).ready(function() {
  $("#ticket-error-box").hide();
});
//-----------------------------------------------------------------------//
// validate ticket input
$("#ticket-submit").on("click", function(){
	
	var output = new Array();
	
	if(!$("#new-ticket-name").val()){
		output.push("Du musst einen Namen angeben.");
	}
	if(!$("#new-ticket-group-text").val()){
		output.push("Du musst eine Zielgruppe angeben.");
	}
	if(!$.isNumeric($("#new-ticket-group-effort").val())){
		output.push("Die Aufwandszeit muss ein Zahl sein");
	}
	else if($("#new-ticket-group-effort").val() < 0 || 
			$("#new-ticket-group-effort").val() > 9999){
		output.push("Die Aufwandszeit muss zwischen 0 und 9999 liegen");
	}
	
	
	
	
	
	if(output.length != 0){
		var outtext = "<h4>!Fehler</h4><br/>" + output.join("<br/>");
		$("#ticket-error-box").html(outtext)
		$("#ticket-error-box").show();
	}
	else{
		
		$("#ticket-error-box").html("");
		$("#ticket-error-box").hide();
	}
});

$(".new-ticket-group-item-g").on("click", function(){
	$("#new-ticket-group-text").val($(this).text());
});

$(".new-ticket-group-item-m").on("click", function(){
	$("#new-ticket-group-text").val($(this).text());
});

$(".new-ticket-priority-item").on("click", function(){
	$("#new-ticket-priority").text($(this).text());
});


$(".new-ticket-status-item").on("click", function(){
	$("#new-ticket-status").text($(this).text());
});
//-----------------------------------------------------------------------//
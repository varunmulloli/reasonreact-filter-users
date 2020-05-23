let withMarginBottom = ReactDOMRe.Style.make(
  ~marginBottom="16px", 
());

let container = ReactDOMRe.Style.make(
  ~width="fit-content",
  ~background="white",
  ~padding="16px", 
());

let fullWidth = ReactDOMRe.Style.make(
  ~width="100%", 
());

let clickableItem = ReactDOMRe.Style.make(
  ~cursor="pointer", 
());

let modalOverlay = ReactDOMRe.Style.make(
  ~position="fixed", 
  ~top="0", 
  ~left="0", 
  ~width="100%", 
  ~height="100%", 
  ~zIndex="50", 
  ~background="#003264", 
  ~opacity="0.7",
());

let modalContainer = ReactDOMRe.Style.make(
  ~display="block", 
  ~position="fixed", 
  ~zIndex="100", 
  ~maxWidth="100%", 
  ~height="200px", 
  ~maxHeight="100%", 
  ~left="50%", 
  ~top="25%", 
  ~transform="translate(-50%, -50%)", 
());


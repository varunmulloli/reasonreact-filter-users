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
  ~visibility="hidden",
  ~backfaceVisibility="hidden",
());

let visibleModalContainer = ReactDOMRe.Style.combine(
  modalContainer,
   ReactDOMRe.Style.make(
    ~visibility="visible",
  ())
);

let modalContent = ReactDOMRe.Style.make(
  ~position="relative",
  ~transform="scale(0.7)",
  ~opacity="0",
  ~transition="all 0.3s",
());

let visibleModalContent = ReactDOMRe.Style.combine(
  modalContent,
  ReactDOMRe.Style.make(
    ~transform="scale(1)",
    ~opacity="1",
  ())
);

let modalOverlay = ReactDOMRe.Style.make(
  ~position="fixed", 
  ~top="0", 
  ~left="0", 
  ~width="100%", 
  ~height="100%", 
  ~zIndex="50", 
  ~background="#003264", 
  ~opacity="0",
  ~visibility="hidden",
  ~transition="all 0.3s",
());

let visibleModalOverlay = ReactDOMRe.Style.combine(
  modalOverlay,
  ReactDOMRe.Style.make(
    ~visibility="visible",
    ~opacity="0.7",
  ())
);
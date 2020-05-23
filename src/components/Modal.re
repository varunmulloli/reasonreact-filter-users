[@react.component]
let make = (~modalOpen: bool, ~setModalOpen: bool => unit, ~children) => {
  let modalContainerCSS = modalOpen ? Styles.visibleModalContainer : Styles.modalContainer;
  let modalContentCSS = modalOpen ? Styles.visibleModalContent : Styles.modalContent;
  let modalOverlayCSS = modalOpen ? Styles.visibleModalOverlay : Styles.modalOverlay;


  <>
    <div style=modalContainerCSS>
      <div style=modalContentCSS>
        {children}
      </div>
    </div>

    <div onClick=(_ => setModalOpen(false)) style=modalOverlayCSS></div>
  </>
};